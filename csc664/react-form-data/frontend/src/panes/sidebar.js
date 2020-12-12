import React, {Component} from 'react';
import clsx from 'clsx';
import { makeStyles, useTheme } from '@material-ui/core/styles';
import Drawer from '@material-ui/core/Drawer';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import List from '@material-ui/core/List';
import CssBaseline from '@material-ui/core/CssBaseline';
import Typography from '@material-ui/core/Typography';
import Divider from '@material-ui/core/Divider';
import IconButton from '@material-ui/core/IconButton';
import MenuIcon from '@material-ui/icons/Menu';
import ChevronLeftIcon from '@material-ui/icons/ChevronLeft';
import ChevronRightIcon from '@material-ui/icons/ChevronRight';
import ListItem from '@material-ui/core/ListItem';
import ListItemIcon from '@material-ui/core/ListItemIcon';
import ListItemText from '@material-ui/core/ListItemText';
import Grid from '@material-ui/core/Grid';
import ViewPane from './viewpane'
import SearchPane from './searchpane'
import ImgScroll from './imgscroll'
import ImageIcon from '@material-ui/icons/Image';
import LabelIcon from '@material-ui/icons/Label';
import AddIcon from '@material-ui/icons/Add';
import Box from '@material-ui/core/Box';

import { connect } from 'react-redux';
import { imageModal } from '../redux/actions';
import { facetModal } from '../redux/actions';

const drawerWidth = 240;

const useStyles = makeStyles((theme) => ({
  root: {
    display: 'flex',
  },
  appBar: {
    zIndex: theme.zIndex.drawer + 1,
    transition: theme.transitions.create(['width', 'margin'], {
      easing: theme.transitions.easing.sharp,
      duration: theme.transitions.duration.leavingScreen,
    }),
  },
  appBarShift: {
    marginLeft: drawerWidth,
    width: `calc(100% - ${drawerWidth}px)`,
    transition: theme.transitions.create(['width', 'margin'], {
      easing: theme.transitions.easing.sharp,
      duration: theme.transitions.duration.enteringScreen,
    }),
  },
  menuButton: {
    marginRight: 36,
  },
  hide: {
    display: 'none',
  },
  drawer: {
    width: drawerWidth,
    flexShrink: 0,
    whiteSpace: 'nowrap',
  },
  drawerOpen: {
    width: drawerWidth,
    transition: theme.transitions.create('width', {
      easing: theme.transitions.easing.sharp,
      duration: theme.transitions.duration.enteringScreen,
    }),
  },
  drawerClose: {
    transition: theme.transitions.create('width', {
      easing: theme.transitions.easing.sharp,
      duration: theme.transitions.duration.leavingScreen,
    }),
    overflowX: 'hidden',
    width: theme.spacing(7) + 1,
    [theme.breakpoints.up('sm')]: {
      width: theme.spacing(9) + 1,
    },
  },
  toolbar: {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'flex-end',
    padding: theme.spacing(0, 1),
    // necessary for content to be below app bar
    ...theme.mixins.toolbar,
  },
  content: {
    flexGrow: 1,
    padding: theme.spacing(3),
  },
}));

class Sidebar extends Component {

constructor() {
  super();
}

componentDidUpdate() {
  
}

render() {
  return (
    <div style={{display: 'flex',}}>
      <CssBaseline />
      <Drawer
        variant="permanent"
        style={{
          width: 89,
          flexShrink: 0,
          whiteSpace: 'nowrap',
        }}      >
        <List>

            <ListItem button onClick={this.props.imageModal}>
              <ListItemIcon><AddIcon/><ImageIcon /> </ListItemIcon>
              <ListItemText />
            </ListItem>

            <ListItem button onClick={this.props.facetModal}>
              <ListItemIcon><AddIcon/> <LabelIcon /> </ListItemIcon>
              <ListItemText />
            </ListItem>

        </List>
      </Drawer>

      <Grid container direction="row" style={{flex: "fill"}}>
        <Grid container item direction="column" xs={12}>
          <Grid container item direction="row">
            <Grid item xs={6}>
              <ViewPane />
            </Grid>
            <Grid item xs={6}>
              <SearchPane />
            </Grid>
          </Grid>
          <Grid item>
            <ImgScroll />
          </Grid>
        </Grid>
      </Grid>

    </div>
  );}
}

export default connect(null, {imageModal, facetModal})(Sidebar)
