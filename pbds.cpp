#include <ext/pb_ds/assoc_container.hpp>
template <typename K, typename V, typename Comp = std::less<K>> using ordered_map = __gnu_pbds::tree<K, V, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>> using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;
// s.find_by_order(k)     ->  kth element
// s.order_of_key(k)      ->  number of elements less than k (first elements in case of map)