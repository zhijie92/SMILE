/* 
 * File:   MembershipRanking.h
 * Author: Sky
 *
 * Created on February 20, 2016, 9:48 PM
 */
//Member will store ranking enum only
#include <iostream>
#include <string>
#ifndef MEMBERSHIPRANKING_H
#define	MEMBERSHIPRANKING_H
using namespace std;
enum Ranking {bronze,sliver,gold,platinum};
class MembershipRanking {
public:
    MembershipRanking();
    MembershipRanking(Ranking);
    MembershipRanking(const MembershipRanking& orig);
    virtual ~MembershipRanking();
    void viewRankingInfo();
  
protected: 
    string rankingInfo;
    float membershipFees;
    float discountRates;
    Ranking rank;
    string freeGift;
    
    
private:
    
};

#endif	/* MEMBERSHIPRANKING_H */

