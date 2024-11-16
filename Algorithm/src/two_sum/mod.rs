use std::collections::HashMap;


pub fn solve(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut value_to_index = HashMap::with_capacity(nums.len());

    for (index, num) in nums.into_iter().enumerate() {
        if let Some(&pair_index) = value_to_index.get(&(target - num)) {
            return vec![pair_index as i32, index as i32];
        }
        value_to_index.insert(num, index);
    }

    vec![]
}
