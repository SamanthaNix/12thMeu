class XtdGearModels {
  class CfgWeapons {

    class twelfth_MA_6 {
      label="12th MA-6";
      options[] = {"gen","type","camo"};
      class gen {
        alwaysSelectable = 1;
        label="Generation";
        values[]={"new","old"};
        class new {label="New";};
        class old {label="Old";};
      };
      class type {
        alwaysSelectable = 1;
        label="Model";
        values[]={"MA_6","MA_6K","MA_6D","MA_6A","MA_6B","MA_6AL"};
        class MA_6 {label="MA-6";};
        class MA_6K {label="MA-6K";};
        class MA_6D {label="MA-6D";};
        class MA_6A {label="MA-6A";};
        class MA_6B {label="MA-6B";};
        class MA_6AL {label="MA-6AL";};
      };
      class camo {
        alwaysSelectable = 1;
        changeingame = 1;
        label="Weapon Camo";
        values[]={"neutral","green"};
        class neutral {label="Default";actionLabel = "Change to default"; };
        class green {label="Green";actionLabel = "Change to green"; };
      };
    };
  };
};

class XtdGearInfos {
  class CfgWeapons {
    class twelfth_MA6{
      model = "twelfth_MA_6";
      gen = "new";
      type = "MA_6";
      camo = "neutral";
    };
    class twelfth_MA6_green{
      model = "twelfth_MA_6";
      gen = "new";
      type = "MA_6";
      camo = "green";
    };
    class twelfth_MA6_K{
      model = "twelfth_MA_6";
      gen = "new";
      type = "MA_6K";
      camo = "neutral";
    };
    class twelfth_MA6_K_Green{
      model = "twelfth_MA_6";
      gen = "new";
      type = "MA_6K";
      camo = "green";
    };
    class twelfth_MA6_D{
      model = "twelfth_MA_6";
      gen = "old";
      type = "MA_6D";
      camo = "neutral";
    };
    class twelfth_MA6_A_BOX{
      model = "twelfth_MA_6";
      gen = "old";
      type = "MA_6A";
      camo = "neutral";
    };
    class twelfth_MA6_B{
      model = "twelfth_MA_6";
      gen = "old";
      type = "MA_6B";
      camo = "neutral";
    };
    class twelfth_MA6_AL{
      model = "twelfth_MA_6";
      gen = "old";
      type = "MA_6AL";
      camo = "neutral";
    };
  };
};