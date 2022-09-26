

class sa
{
};

class sb
{};

void staticcastmain2()
{
    sa a;
    sb* b = reinterpret_cast<sb*>(&a);
}