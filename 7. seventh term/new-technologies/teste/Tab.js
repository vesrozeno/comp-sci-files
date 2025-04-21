import React from "react";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import TelaA from "./TelaA";
import TelaB from "./TelaB";
import Ionicons from "react-native-vector-icons/Ionicons";
import MaterialCommunityIcons from "react-native-vector-icons";
// import TelaC from "./TelaC";

const Tab = createBottomTabNavigator();

export default (props) => (
  <Tab.Navigator
    screenOptions={{
      tabBarActiveTintColor: "red",
      tabBarInactiveTintColor: "blue",
      tabBarLabelStyle: { fontSize: 30 },
    }}
    initialRouteName="TelaB"
  >
    <Tab.Screen name="TelaA" component={TelaA} />
    <Tab.Screen name="TelaB" component={TelaB} />
    {/* <Tab.Screen name="TelaC" component={TelaC} /> */}
  </Tab.Navigator>
);
