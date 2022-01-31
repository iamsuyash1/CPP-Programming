#include<iostream>
using namespace std;

// Following SRP
class DesignDepartment{};
class ManufacturingDepartment{};
class PaintingDepartment{};
class QualityCheckDepartment{};
class MarketingDepartment{};


// Not following SRP
class ProductDevelopment
{
    public:
        void DesignDepartment(){}         
        void ManufacturingDepartment(){}
        void PaintingDepartment(){}
        void QualityCheckDepartment(){}
        void MarketingDepartment(){}
};

