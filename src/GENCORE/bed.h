#ifndef BEDREGION_H
#define BEDREGION_H

#include <Rcpp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <math.h>
#include "options.h"

using namespace std;
namespace GENCORE {
    class BedRegion{
    public:
        BedRegion(string chr, int start, int end, string name){
            mChr = chr;
            mStart = start;
            mEnd = end;
            mName = name;
            mCount = 0;
            mTid = -1;
        }
        inline void dump() {
            //Rcpp::warning( mChr + ": " + mName + "\n");
            //Rcpp::Rcerr( mChr + ":" + mStart + "-" + mEnd + " " + mName + ", " + mCount + "\n");
            Rcpp::warning( mChr + ":" + to_string(mStart) + "-" + to_string(mEnd) + " " + mName + ", " + to_string(mCount) + "\n");
        }
        inline int getAvgDepth() {
            if(mEnd <= mStart)
                return 0;
            else
                return round(double(mCount)/(mEnd - mStart));
        }
    
    public:
        string mChr;
        int mStart;
        int mEnd;
        string mName;
        // for depth counting
        long mCount;
        // contig id
        int mTid;
    };
    
    class Bed{
    public:
        Bed(Options* opt);
        void loadFromFile();
        void copyFrom(Bed* other);
        void dump();
        void statDepth(int tid, int start, int len);
        void reportJSON(ofstream& ofs);
        string getPlotX(int c);
        string getPlotY(int c, bool negative = false);
        vector<vector<long>> getDepthList();
    
    public:
        Options* mOptions;
        vector<vector<BedRegion>> mContigRegions;
    };
}

#endif
