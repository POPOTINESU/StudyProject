// 継承による Adapter パターン
interface Target {
  getCSVData(): string;
}

class NewLibrary {
  getJsonData() {
    return [
      {
        data1: 'json_A',
        data2: 'json_B',
      },
      {
        data1: 'json_dataC',
        data2: 'json_dataD',
      },
    ];
  }
}

// 継承を用いた Adapter
class JsonToCsvAdapter extends NewLibrary implements Target {
  getCSVData(): string {
    const jsonData = this.getJsonData();

    const header = Object.keys(jsonData[0]).join(',') + '\n';
    const body = jsonData.map((d) => Object.values(d).join(',')).join('\n');

    return header + body;
  }
}

// 委譲（Composition）による Adapter
class JsonToCsvAdapterByDelegation implements Target {
  private adaptee: NewLibrary;

  constructor(adaptee: NewLibrary) {
    this.adaptee = adaptee;
  }

  getCSVData(): string {
    const jsonData = this.adaptee.getJsonData();

    const header = Object.keys(jsonData[0]).join(',') + '\n';
    const body = jsonData.map((d) => Object.values(d).join(',')).join('\n');

    return header + body;
  }
}

// 使用例
const jsonLibrary = new NewLibrary();
const adapter1 = new JsonToCsvAdapter(); // 継承
const adapter2 = new JsonToCsvAdapterByDelegation(jsonLibrary); // 委譲

console.log('=== 継承を用いた Adapter ===');
console.log(adapter1.getCSVData());

console.log('\n=== 委譲を用いた Adapter ===');
console.log(adapter2.getCSVData());
