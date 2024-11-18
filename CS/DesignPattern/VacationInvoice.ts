type VacationInvoiceValue = {
  startingDate: Date;
  endingDate: Date;
  hotelDays: number;
  hotelType: string;
  fairyWorldDays: number;
  adultFastPass: number;
  kidsFastPass: number;
  arcadePass: number;
  VIPTour: "VIP tour 1" | "VIP tour 2" | "VIP tour 3";
  regularRestaurants: "breakfast" | "lunch" | "dinner";
  fineDiningRestaurants: "breakfast" | "lunch" | "dinner";
};
class VacationInvoice {
  private vacationInvoiceValue: VacationInvoiceValue;

  constructor(vacationInvoiceValue: VacationInvoiceValue) {
    this.vacationInvoiceValue = vacationInvoiceValue;
  }

  getValue() {
    // 後からロジックを追加する
    return 
  }
}

class VacationInvoiceBuilder {
  
}

