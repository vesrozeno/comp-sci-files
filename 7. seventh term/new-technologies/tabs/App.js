import { StatusBar } from "expo-status-bar";
import React from "react";
import { StyleSheet, Text, View } from "react-native";
import Tab from "./componentes/Tab";
import { NavigationContainer } from "@react-navigation/native";
import Drawer from "./componentes/Drawer";

export default function App() {
  return (
    <NavigationContainer>
      <Drawer></Drawer>
    </NavigationContainer>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
});
