import React, { Component } from 'react';
import axios from 'axios';
import Grid from '@material-ui/core/Grid';
import { makeStyles } from '@material-ui/core/styles';
import Typography from '@material-ui/core/Typography';
import Container from '@material-ui/core/Container';
import spiri from '../test_images/143336_HYA0IdNQ_gSRB9hZ.png'
import Box from '@material-ui/core/Box';

const useStyles = makeStyles({
  paneDiv: {
    border: 3,
    borderStyle: 'inset',
    height: '100%',
    backgroundColor: '#cfe8fc',
    borderColor: 'green'

  }
})

export default function SearchPane() {

  const classes = useStyles();

  return (
    <Box className={classes.paneDiv}>
      <img src={spiri} />
    </Box>
  );

}
