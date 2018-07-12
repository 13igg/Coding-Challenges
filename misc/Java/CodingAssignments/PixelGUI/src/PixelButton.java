import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.util.*;
import java.*;
public class PixelButton extends JButton
{
	private int row;
	private int col;
	//add rgb values?
	public PixelButton(int r, int c)
	{
		super();
		setRow(r);
		setCol(c);
		String desc = r + ", " + c;
		this.setToolTipText(desc);
	}
	public int getCol() {
		return col;
	}
	public void setCol(int col) {
		this.col = col;
	}
	public int getRow() {
		return row;
	}
	public void setRow(int row) {
		this.row = row;
	}
}
