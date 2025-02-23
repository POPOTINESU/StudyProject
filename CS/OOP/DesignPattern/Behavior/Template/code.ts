/**
 * TestTemplateで流れのtemplateを定義しておいて
 * それぞれのサービスで定義することによって、流れを保ちつつ、簡単に記載することができる
 */

abstract class TestTemplate {
  test() {
    this.setup();
    this.execute();
    this.assert();
  }

  abstract setup();
  abstract execute();

  assert() {
    console.log('assert');
  }
}

class UserServiceTest extends TestTemplate {
  setup() {
    console.log('set up user');
  }

  execute() {
    console.log('execute user');
  }
}

class AdminServiceTest extends TestTemplate {
  setup() {
    console.log('set up admin');
  }

  execute() {
    console.log('execute admin');
  }
}

const main = () => {
  const userServiceTest = new UserServiceTest();
  const adminServiceTest = new AdminServiceTest();

  userServiceTest.test();
  adminServiceTest.test();
};
