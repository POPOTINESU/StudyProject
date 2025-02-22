// ユーザーが仕様をしならくても使えるもの

class Television {
  private power = true;
  private switch = new Switch();

  toggleSwitch() {
    this.power = this.switch.toggle(this.power);
    console.log(`power: ${this.switch ? 'on' : 'off'}`);
  }
}

class Switch {
  toggle(power: boolean) {
    return !power;
  }
}

const television = new Television();
television.toggleSwitch();
