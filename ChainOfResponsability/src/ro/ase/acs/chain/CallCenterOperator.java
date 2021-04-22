package ro.ase.acs.chain;

public class CallCenterOperator extends CallCenterHandler {

	@Override
	public boolean refund(double suma) {
		if(suma < 100) {
			System.out.println("Refund performed by call center operator");
			return true;
			
		}
		else if(nextHandler != null) {
			return nextHandler.refund(suma);	
		}
		else {
			System.out.println("Refund not possible!");
			return false;
		}
	}
}
