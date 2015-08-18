
(function ($, rho, rhoUtil) {
    'use strict';

    var moduleNS = 'Rho.Lightsensor';
    var apiReq = rhoUtil.apiReqFor(moduleNS);


    // === Lightsensor class definition ===

    function Lightsensor() {
        var id = null;
        this.getId = function () {return id;};

        if (1 == arguments.length && arguments[0][rhoUtil.rhoIdParam()]) {
            if (moduleNS != arguments[0][rhoUtil.rhoClassParam()]) {
                throw "Wrong class instantiation!";
            }
            id = arguments[0][rhoUtil.rhoIdParam()];
        } else {
            id = rhoUtil.nextId();
            // constructor methods are following:
            
        }
    };

    // === Lightsensor instance properties ===

    rhoUtil.createPropsProxy(Lightsensor.prototype, [
        { propName: 'delay', propAccess: 'rw' }
    ], apiReq, function(){ return this.getId(); });

    // === Lightsensor instance methods ===

    rhoUtil.createMethodsProxy(Lightsensor.prototype, [
    
          // function(/* const rho::Hashtable<rho::String, rho::String>& */ propertyMap, /* optional function */ oResult)
          { methodName: 'startListening', nativeName: 'startListening', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
    
          // function(/* optional function */ oResult)
        , { methodName: 'stopListening', nativeName: 'stopListening', valueCallbackIndex: 0 }
    
    ], apiReq, function(){ return this.getId(); });

    

    rhoUtil.createRawPropsProxy(Lightsensor.prototype, [
    ]);

    // === Lightsensor constants ===

    
            Lightsensor.FAST = '1'; 
    
            Lightsensor.NORMAL = '0'; 
    



    // === Lightsensor static properties ===

    rhoUtil.createPropsProxy(Lightsensor, [
    ], apiReq);

    // === Lightsensor static methods ===

    rhoUtil.createMethodsProxy(Lightsensor, [
    
          // function(/* optional function */ oResult)
          { methodName: 'enumerate', nativeName: 'enumerate', persistentCallbackIndex: 0, valueCallbackIndex: 2 }
    
    ], apiReq);

    // === Lightsensor default instance support ===
    

        rhoUtil.createPropsProxy(Lightsensor, [
            { propName: 'defaultInstance:getDefault:setDefault', propAccess: 'rw', customSet: function(obj) { if(!obj || 'function' != typeof obj.getId){ throw 'Default object should provide getId method!' }; Lightsensor.setDefaultID(obj.getId()); } }
          , { propName: 'defaultID:getDefaultID:setDefaultID', propAccess: 'rw' }
        ], apiReq);

        Lightsensor.getId = function() {
            return Lightsensor.getDefaultID();
        }

        // === Lightsensor default instance properties ===

        rhoUtil.createPropsProxy(Lightsensor, [
            { propName: 'delay', propAccess: 'rw' }
        ], apiReq, function(){ return this.getId(); });

        // === Lightsensor default instance methods ===

        rhoUtil.createMethodsProxy(Lightsensor, [
        
              // function(/* const rho::Hashtable<rho::String, rho::String>& */ propertyMap, /* optional function */ oResult)
              { methodName: 'startListening', nativeName: 'startListening', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
        
              // function(/* optional function */ oResult)
            , { methodName: 'stopListening', nativeName: 'stopListening', valueCallbackIndex: 0 }
        
        ], apiReq, function(){ return this.getId(); });

        // will reuse already defined methods
        rhoUtil.createRawPropsProxy(Lightsensor, [
        ]);

    

    rhoUtil.namespace(moduleNS, Lightsensor);

    

    

})(Rho.jQuery, Rho, Rho.util);
