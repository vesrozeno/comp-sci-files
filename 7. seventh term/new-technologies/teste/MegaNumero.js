import React from "react";
import { View, Text, StyleSheet } from "react-native";

export default (props) => {
  return (
    <View style={style.container}>
      <Text style={style.Num}>{props.num}</Text>
    </View>
  );
};
const style = StyleSheet.create({
  container: {
    height: 50,
    width: 50,
    backgroundColor: "white",
    margin: 5,
    borderRadius: 25,
    justifyContent: "center",
    borderWidth: 2,
    borderColor: "black",
  },
  Num: {
    color: "black",
    fontSize: 28,
    fontWeight: "bold",
    textAlign: "center",
  },
});
