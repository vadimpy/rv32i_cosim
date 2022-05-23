#include <elfio/elfio.hpp>
#include <vector>
#include <cstdint>

namespace simtools {

struct Elf32Seg {
    uint32_t start_addr; 
    std::vector<uint32_t> data;
};

struct Elf32Data {
    uint32_t entry;
    std::vector<Elf32Seg> segs;
};

ELFIO::elfio rv32_elf_reader(const std::string& path) {

    ELFIO::elfio reader;
    reader.load(path);

    if (reader.get_class() != ELFIO::ELFCLASS32) {
        std::cerr << "Executable must be ELF32 class\n";
    }

    if (reader.get_machine() != ELFIO::EM_RISCV) {
        std::cerr << "Machine must be RISCV\n";
    }

    return reader;
}

int load_elf(const std::string& path, void * sim_mem) {

    ELFIO::elfio reader = rv32_elf_reader(path);

    ELFIO::Elf_Half seg_num = reader.segments.size();
    for (int i = 0; i < seg_num; ++i) {
        const ELFIO::segment* pseg = reader.segments[i];
        const void * seg_data = pseg->get_data();
        size_t file_size = pseg->get_file_size();
        size_t virt_addr = pseg->get_virtual_address();
        std::memcpy(static_cast<uint8_t*>(sim_mem) + virt_addr, seg_data, file_size);
    }

    return reader.get_entry();
}

Elf32Data get_elf_data(const std::string& path) {

    ELFIO::elfio reader = rv32_elf_reader(path);
    Elf32Data elf_data;

    elf_data.entry = reader.get_entry();

    ELFIO::Elf_Half seg_num = reader.segments.size();
    for (int i = 0; i < seg_num; ++i) {
        const ELFIO::segment* pseg = reader.segments[i];
        const void * seg_data = pseg->get_data();
        uint32_t file_size = pseg->get_file_size();
        uint32_t start_addr = pseg->get_virtual_address();

        std::vector<uint32_t> seg_data_v(file_size / 4);
        std::memcpy(seg_data_v.data(), seg_data, file_size);

        Elf32Seg seg_info { start_addr, std::move(seg_data_v) };
        elf_data.segs.push_back(std::move(seg_info));
    }

    return elf_data;
}

}