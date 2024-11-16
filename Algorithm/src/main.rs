mod merge;

fn main() {
    let mut nums1 = vec![0];
    let mut nums2 = vec![1];

    merge::Solution::solve(&mut nums1, 0, &mut nums2, 1);

    println!("Result: {:?}", nums1);
}