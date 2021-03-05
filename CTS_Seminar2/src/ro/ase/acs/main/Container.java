package ro.ase.acs.main;

import java.util.HashMap;
import java.util.Map;

public class Container {

	
	
	Map<Class<?>, Class<?>> map = new HashMap<>();
	
	
	public void Register(Class<?> contract, Class<?> implementation) {
		if(!map.containsKey(contract)) {
			map.put(contract, implementation);
		}
		
	}
	
	
	
	
}