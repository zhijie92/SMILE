#include "MembershipRanking.h"

MembershipRanking::MembershipRanking() {
    
}

MembershipRanking::MembershipRanking(const MembershipRanking& orig) {
}

MembershipRanking::MembershipRanking(Ranking rank)
{
    // 0 is bronze
    if (rank == 0)
    {
        this->membershipFees = 100;
        this->rankingInfo="Your membership is bronze";
        this->discountRates = 2;
        this->rank = bronze;
        this->freeGift="Sorry no free gift";
    }
    //sliver
    else if (rank == 1)
    {
        this->membershipFees = 150;
        this->rankingInfo="Your membership is sliver";
        this->discountRates = 4;
        this->rank = sliver;
        this->freeGift="Sorry no free gift";
    }
    else if (rank == 2)
    {
        this->membershipFees = 200;
        this->rankingInfo="Your membership is Gold";
        this->discountRates = 6;
        this->rank = gold;
        this->freeGift="You will receive free gift every year";
    }
    else if (rank == 3)
    {
        this->membershipFees = 300;
        this->rankingInfo="Your membership is Platinum";
        this->discountRates = 8;
        this->rank = platinum;
        this->freeGift="You will receive free gift every year";
    }
}
void MembershipRanking::viewRankingInfo() {
    cout << this->rankingInfo;
  
    cout << "Membership fees: " << this->membershipFees << endl;
    cout << "Discount rates: " << this->discountRates << endl;
    cout << "Free Gift: " << this->freeGift << endl;
}
MembershipRanking::~MembershipRanking() {
}

