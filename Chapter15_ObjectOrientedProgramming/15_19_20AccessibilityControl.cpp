class Base
{
public:
    void pub_mem();

protected:
    int prot_mem;

private:
    char priv_mem;
};
struct PubDerived : public Base
{
    void memfcn(Base &b) { b = *this; }
};
struct PrivDerived : private Base
{
    void memfcn(Base &b) { b = *this; }
};
struct ProtDerived : protected Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_PubD : public PubDerived
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_PrivD : public PrivDerived
{
    void memfcn(Base &b) { b = *this; } // 仅有此函数不合法。
                                        // 注意：该赋值过程中发生了*this到Base&的绑定，
                                        // 而派生类D的成员和友元始终可以访问到直接基类B的类型转换，
                                        // D的派生类DD可以访问到B的类型转换当且仅当B的公有成员可访问，
                                        // 亦即采用public或protected继承。
};
struct Derived_from_protD : public ProtDerived
{
    void memfcn(Base &b) { b = *this; }
};
