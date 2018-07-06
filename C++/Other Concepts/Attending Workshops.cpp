//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
typedef pair<int,int> pii;
typedef vector<pii> Available_Workshops;
Available_Workshops* initialize(int *start_time,int *duration,int n){
	auto r=new Available_Workshops(n);
	for(int i=0;i<n;i++)r->at(i).first=start_time[i],r->at(i).second=start_time[i]+duration[i];
	return r;
}
int CalculateMaxWorkshops(Available_Workshops* data){
	sort(data->begin(),data->end(),[](const pii &a,const pii &b){return a.second<b.second;});
	int f=0,r=0;
	for(int i=0;i<data->size();i++){
		if(data->at(i).first>=f){
			r++;
			f=data->at(i).second;
		}
	}
	return r;
}
