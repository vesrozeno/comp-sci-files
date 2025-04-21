import React from "react";
import { Text, View, StyleSheet } from "react-native";

export default (props) => {
  const styles = StyleSheet.create({
    container: {
      height: 100,
      width: 100,
      backgroundColor: props.cor || "#000",
      borderRadius: 16,
      margin: 5,
    },
  });
  return <View style={styles.container}></View>;
};
