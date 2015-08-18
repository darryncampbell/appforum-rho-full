
(function ($, rho, rhoUtil) {
    'use strict';

    var moduleNS = 'Rho.Cordovabarcode';
    var apiReq = rhoUtil.apiReqFor(moduleNS);


    // === Cordovabarcode class definition ===

    function Cordovabarcode() {
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

    // === Cordovabarcode instance properties ===

    rhoUtil.createPropsProxy(Cordovabarcode.prototype, [
    ], apiReq, function(){ return this.getId(); });

    // === Cordovabarcode instance methods ===

    rhoUtil.createMethodsProxy(Cordovabarcode.prototype, [
    
          // function(/* const rho::Hashtable<rho::String, rho::String>& */ propertyMap, /* optional function */ oResult)
          { methodName: 'scan', nativeName: 'scan', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
    
    ], apiReq, function(){ return this.getId(); });

    

    rhoUtil.createRawPropsProxy(Cordovabarcode.prototype, [
    ]);

    // === Cordovabarcode constants ===

    



    // === Cordovabarcode static properties ===

    rhoUtil.createPropsProxy(Cordovabarcode, [
    ], apiReq);

    // === Cordovabarcode static methods ===

    rhoUtil.createMethodsProxy(Cordovabarcode, [
    
          // function(/* optional function */ oResult)
          { methodName: 'enumerate', nativeName: 'enumerate', persistentCallbackIndex: 0, valueCallbackIndex: 2 }
    
    ], apiReq);

    // === Cordovabarcode default instance support ===
    

        rhoUtil.createPropsProxy(Cordovabarcode, [
            { propName: 'defaultInstance:getDefault:setDefault', propAccess: 'rw', customSet: function(obj) { if(!obj || 'function' != typeof obj.getId){ throw 'Default object should provide getId method!' }; Cordovabarcode.setDefaultID(obj.getId()); } }
          , { propName: 'defaultID:getDefaultID:setDefaultID', propAccess: 'rw' }
        ], apiReq);

        Cordovabarcode.getId = function() {
            return Cordovabarcode.getDefaultID();
        }

        // === Cordovabarcode default instance properties ===

        rhoUtil.createPropsProxy(Cordovabarcode, [
        ], apiReq, function(){ return this.getId(); });

        // === Cordovabarcode default instance methods ===

        rhoUtil.createMethodsProxy(Cordovabarcode, [
        
              // function(/* const rho::Hashtable<rho::String, rho::String>& */ propertyMap, /* optional function */ oResult)
              { methodName: 'scan', nativeName: 'scan', persistentCallbackIndex: 1, valueCallbackIndex: 3 }
        
        ], apiReq, function(){ return this.getId(); });

        // will reuse already defined methods
        rhoUtil.createRawPropsProxy(Cordovabarcode, [
        ]);

    

    rhoUtil.namespace(moduleNS, Cordovabarcode);

    

    

})(Rho.jQuery, Rho, Rho.util);
