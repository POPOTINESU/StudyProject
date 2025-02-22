// SがTの派生系(SがTを継承している状態)であれば、プログラム内でT型のオブジェクトが使用されている箇所は
// 全てS型のオブジェクトであるべき
// つまり派生クラスは基底クラスと同じ振る舞いを持つべき
// 

class Human {
  age = 20;
  getAge() {
    return this.age;
  }
}

// 別のファイルで使っているからIにしてる
class IStudent extends Human {
  getAge(): number {
    return this.age;
  }
}

// この場合HumanのgetAgeとIStudentのgetAge