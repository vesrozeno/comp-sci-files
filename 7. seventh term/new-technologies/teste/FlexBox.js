import React from "react";
import { Text, View, StyleSheet } from "react-native";
import Quadrado from "./Quadrado";

export default (props) => {
  const styles = StyleSheet.create({
    FlexV1: {
      flex: 1,
      justifyContent: "center",
      flexDirection: "row",
      alignItems: "center",
      backgroundColor: "#fff",
      position: "absolute",
      display: "flex",
      flexWrap: "wrap",
    },
  });
  return (
    <View style={styles.FlexV1}>
      <Quadrado cor="blue"></Quadrado>
      <Quadrado cor="yellow"></Quadrado>
      <Quadrado cor="red"></Quadrado>
      <Quadrado cor="green"></Quadrado>
      <Quadrado cor="purple"></Quadrado>
      <Quadrado cor="cyan"></Quadrado>
      <Quadrado cor="grey"></Quadrado>
      <Quadrado cor="black"></Quadrado>
      <Quadrado cor="orange"></Quadrado>
    </View>
  );
};
