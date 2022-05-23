namespace sim {

template<class VModuleClass>
class VModule {
public:
    VModule() : module_p_(std::make_unique<VModuleClass>()), ticks_(0) {}

    ~VModule() {
        module_p_->final();
    }

    uint64_t negedge() {
        ++ticks_;
        module_p_->clk = 0;
        module_p_->eval();
        return ticks_;
    }

    uint64_t posedge() {
        ++ticks_;
        module_p_->clk = 1;
        module_p_->eval();
        return ticks_;        
    }

    uint64_t clock() {
        posedge();
        return negedge();
    }

    uint64_t ticks() const {
        return ticks_;
    }

    std::unique_ptr<VModuleClass>& operator->() {
        return module_p_;
    }

private:
    std::unique_ptr<VModuleClass> module_p_;

protected:
    uint64_t ticks_;
};
}
