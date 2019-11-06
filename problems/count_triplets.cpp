//
// Created by elshahawy on 27.10.2019.
//
long countTriplets(vector<long> arr, long r) {
  map<int,long> mp2, mp3;
  int val;
  long long res = 0;
  for (int i{0}; i < arr.size(); ++i)
  {
    if (mp3.count(arr[i]))
      res += mp3[arr[i]];
    if (mp2.count(arr[i]))
      mp3[arr[i]*r] += mp2[arr[i]];
    mp2[arr[i]*r]++;
  }
  return res;
}

int main()
{
  auto bb = countTriplets(vector<long>{1237,2,1,2,4} , 2);
  std::cout << "result: " << bb << "\n";
}
