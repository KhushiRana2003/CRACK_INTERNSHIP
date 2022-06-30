class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int j = 0, seat = 1, maxSeats = 1;
        
        for(int i = 0; i < seats.size(); i++){
            if(seats[i] == 1 and seats[j] == 0){
                seat = i-j;
                maxSeats = max(seat,maxSeats);
                j=i;
            }
            
            if(seats[i] == 1 and seats[j] == 1){
                seat = min(abs(j-(j+i)/2),i-(j+i)/2);
                maxSeats = max(seat,maxSeats);
                j=i;
            }
            
            if(i == seats.size()-1){
                seat = i-j;
                maxSeats = max(seat,maxSeats);
                j=i;
            }
        }
        return maxSeats;
    }
};

