<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.3">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="con-harting-v">
<description>&lt;b&gt;Harting Connectors&lt;/b&gt;&lt;p&gt;
PC board mounted ribbon cable connectors (IEC 52141), vertical&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="40V">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<wire x1="35.052" y1="-4.191" x2="32.512" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="35.052" y1="-4.191" x2="35.052" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-2.413" x2="-2.032" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.175" x2="-2.032" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.175" x2="-19.558" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-2.413" x2="2.032" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-3.175" x2="2.032" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="28.829" y1="4.191" x2="28.829" y2="4.445" width="0.1524" layer="21"/>
<wire x1="28.829" y1="4.445" x2="27.559" y2="4.445" width="0.1524" layer="21"/>
<wire x1="27.559" y1="4.191" x2="27.559" y2="4.445" width="0.1524" layer="21"/>
<wire x1="28.829" y1="4.191" x2="32.512" y2="4.191" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="4.191" x2="26.162" y2="4.191" width="0.1524" layer="21"/>
<wire x1="21.209" y1="-4.191" x2="2.032" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-4.191" x2="-2.032" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="22.098" y1="-3.175" x2="22.098" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="22.098" y1="-3.175" x2="2.032" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="28.194" y1="-3.175" x2="23.622" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="23.622" y1="-3.175" x2="22.098" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="21.209" y1="-4.191" x2="21.59" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="24.13" y1="-3.683" x2="24.511" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="22.098" y1="-3.429" x2="2.032" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="2.032" y1="-3.429" x2="2.032" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.175" x2="-2.032" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.429" x2="-2.032" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="22.098" y1="-3.429" x2="22.098" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="22.098" y1="-3.683" x2="21.59" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="23.622" y1="-3.175" x2="23.622" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="24.13" y1="-3.683" x2="23.622" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="23.622" y1="-3.683" x2="22.098" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-4.191" x2="-18.669" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-23.495" y1="-4.064" x2="-23.495" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-23.495" y1="-4.064" x2="-24.765" y2="-4.064" width="0.1524" layer="21"/>
<wire x1="-24.765" y1="-4.191" x2="-24.765" y2="-4.064" width="0.1524" layer="21"/>
<wire x1="28.194" y1="3.175" x2="28.194" y2="2.032" width="0.1524" layer="21"/>
<wire x1="26.162" y1="1.397" x2="26.67" y2="1.397" width="0.1524" layer="21"/>
<wire x1="26.162" y1="1.397" x2="26.162" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="28.194" y1="-1.397" x2="27.94" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="28.194" y1="-1.397" x2="28.194" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="28.321" y1="2.032" x2="28.321" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="28.194" y1="2.032" x2="28.321" y2="2.032" width="0.1524" layer="21"/>
<wire x1="28.194" y1="2.032" x2="28.194" y2="1.397" width="0.1524" layer="21"/>
<wire x1="28.194" y1="-2.032" x2="28.321" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="28.194" y1="-2.032" x2="28.194" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="28.321" y1="-2.032" x2="28.448" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="26.67" y1="1.397" x2="26.67" y2="-1.397" width="0.0508" layer="21"/>
<wire x1="26.67" y1="1.397" x2="27.94" y2="1.397" width="0.1524" layer="21"/>
<wire x1="26.67" y1="-1.397" x2="26.162" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="28.956" y1="2.032" x2="28.956" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="28.956" y1="2.032" x2="29.591" y2="2.032" width="0.1524" layer="21"/>
<wire x1="28.956" y1="-2.032" x2="29.591" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="29.591" y1="2.032" x2="29.591" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="29.591" y1="2.032" x2="30.226" y2="2.032" width="0.1524" layer="21"/>
<wire x1="29.591" y1="-2.032" x2="30.226" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="30.226" y1="2.032" x2="30.226" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="30.226" y1="2.032" x2="31.496" y2="2.032" width="0.1524" layer="21"/>
<wire x1="30.226" y1="-2.032" x2="31.496" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="26.162" y1="4.191" x2="26.162" y2="3.429" width="0.0508" layer="21"/>
<wire x1="26.162" y1="4.191" x2="27.559" y2="4.191" width="0.1524" layer="21"/>
<wire x1="27.559" y1="4.191" x2="27.559" y2="3.429" width="0.0508" layer="21"/>
<wire x1="-28.194" y1="3.175" x2="28.194" y2="3.175" width="0.1524" layer="21"/>
<wire x1="27.94" y1="1.397" x2="27.94" y2="-1.397" width="0.0508" layer="21"/>
<wire x1="27.94" y1="1.397" x2="28.194" y2="1.397" width="0.1524" layer="21"/>
<wire x1="27.94" y1="-1.397" x2="26.67" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="31.496" y1="2.032" x2="31.496" y2="2.54" width="0.1524" layer="21"/>
<wire x1="31.496" y1="2.032" x2="32.131" y2="2.032" width="0.1524" layer="21"/>
<wire x1="31.496" y1="2.54" x2="32.512" y2="2.54" width="0.1524" layer="21"/>
<wire x1="32.512" y1="2.54" x2="32.512" y2="4.191" width="0.1524" layer="21"/>
<wire x1="32.512" y1="4.191" x2="35.052" y2="4.191" width="0.1524" layer="21"/>
<wire x1="35.052" y1="1.143" x2="34.29" y2="1.143" width="0.1524" layer="21"/>
<wire x1="35.052" y1="1.143" x2="35.052" y2="4.191" width="0.1524" layer="21"/>
<wire x1="35.052" y1="-1.143" x2="34.29" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="35.052" y1="-1.143" x2="35.052" y2="1.143" width="0.1524" layer="21"/>
<wire x1="32.131" y1="2.032" x2="32.131" y2="1.143" width="0.1524" layer="21"/>
<wire x1="32.131" y1="1.143" x2="32.131" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="32.131" y1="-1.143" x2="32.131" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="32.512" y1="2.54" x2="34.29" y2="1.143" width="0.1524" layer="21"/>
<wire x1="34.29" y1="1.143" x2="32.131" y2="1.143" width="0.1524" layer="21"/>
<wire x1="31.496" y1="-2.54" x2="31.496" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="31.496" y1="-2.032" x2="32.131" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="31.496" y1="-2.54" x2="32.512" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="32.512" y1="-4.191" x2="32.512" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="32.512" y1="-4.191" x2="27.559" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="32.512" y1="-2.54" x2="34.29" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="34.29" y1="-1.143" x2="32.131" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-27.559" y1="3.429" x2="-26.162" y2="3.429" width="0.0508" layer="21"/>
<wire x1="23.622" y1="-3.429" x2="26.162" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="23.622" y1="-3.429" x2="23.622" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="28.321" y1="2.032" x2="28.448" y2="2.032" width="0.1524" layer="21"/>
<wire x1="28.448" y1="2.032" x2="28.956" y2="2.032" width="0.1524" layer="21"/>
<wire x1="27.559" y1="3.429" x2="26.162" y2="3.429" width="0.0508" layer="21"/>
<wire x1="27.559" y1="3.429" x2="28.448" y2="3.429" width="0.0508" layer="21"/>
<wire x1="28.448" y1="3.429" x2="28.448" y2="2.032" width="0.0508" layer="21"/>
<wire x1="28.448" y1="-3.429" x2="28.448" y2="-2.032" width="0.0508" layer="21"/>
<wire x1="28.448" y1="-2.032" x2="28.956" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-35.052" y1="4.191" x2="-32.512" y2="4.191" width="0.1524" layer="21"/>
<wire x1="-35.052" y1="4.191" x2="-35.052" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-24.765" y1="-4.191" x2="-26.162" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-28.194" y1="-3.175" x2="-28.194" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="-1.397" x2="-26.67" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="-1.397" x2="-26.162" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-28.194" y1="1.397" x2="-27.94" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-28.194" y1="1.397" x2="-28.194" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-28.321" y1="-2.032" x2="-28.321" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-28.194" y1="-2.032" x2="-28.321" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-28.194" y1="-2.032" x2="-28.194" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="-28.194" y1="2.032" x2="-28.321" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-28.194" y1="2.032" x2="-28.194" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-28.321" y1="2.032" x2="-28.448" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-26.67" y1="-1.397" x2="-26.67" y2="1.397" width="0.0508" layer="21"/>
<wire x1="-26.67" y1="-1.397" x2="-27.94" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="-26.67" y1="1.397" x2="-26.162" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-28.956" y1="-2.032" x2="-28.956" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-28.956" y1="-2.032" x2="-29.591" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-28.956" y1="2.032" x2="-29.591" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-29.591" y1="-2.032" x2="-29.591" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-29.591" y1="-2.032" x2="-30.226" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-29.591" y1="2.032" x2="-30.226" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-30.226" y1="-2.032" x2="-30.226" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-30.226" y1="-2.032" x2="-31.496" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-30.226" y1="2.032" x2="-31.496" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-27.94" y1="-1.397" x2="-27.94" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-27.94" y1="-1.397" x2="-28.194" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="-27.94" y1="1.397" x2="-26.67" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-31.496" y1="-2.032" x2="-31.496" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-31.496" y1="-2.032" x2="-32.131" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-31.496" y1="-2.54" x2="-32.512" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-32.512" y1="-2.54" x2="-32.512" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-32.512" y1="-4.191" x2="-35.052" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-35.052" y1="-1.143" x2="-34.29" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-35.052" y1="-1.143" x2="-35.052" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-35.052" y1="1.143" x2="-34.29" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-35.052" y1="1.143" x2="-35.052" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-32.131" y1="-2.032" x2="-32.131" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-32.131" y1="-1.143" x2="-32.131" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-32.131" y1="1.143" x2="-32.131" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-32.512" y1="-2.54" x2="-34.29" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-34.29" y1="-1.143" x2="-32.131" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-31.496" y1="2.54" x2="-31.496" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-31.496" y1="2.032" x2="-32.131" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-31.496" y1="2.54" x2="-32.512" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-32.512" y1="4.191" x2="-32.512" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-32.512" y1="2.54" x2="-34.29" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-34.29" y1="1.143" x2="-32.131" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-28.321" y1="-2.032" x2="-28.448" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-28.448" y1="-2.032" x2="-28.956" y2="-2.032" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="-3.429" x2="-19.558" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="-28.448" y1="-3.429" x2="-28.448" y2="-2.032" width="0.0508" layer="21"/>
<wire x1="-28.448" y1="3.429" x2="-28.448" y2="2.032" width="0.0508" layer="21"/>
<wire x1="-28.448" y1="2.032" x2="-28.956" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="3.429" x2="-26.162" y2="4.191" width="0.0508" layer="21"/>
<wire x1="-26.162" y1="3.429" x2="26.162" y2="3.429" width="0.0508" layer="21"/>
<wire x1="-27.559" y1="3.429" x2="-27.559" y2="4.191" width="0.0508" layer="21"/>
<wire x1="-28.829" y1="4.445" x2="-27.559" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-27.559" y1="4.445" x2="-27.559" y2="4.191" width="0.1524" layer="21"/>
<wire x1="-28.829" y1="4.445" x2="-28.829" y2="4.191" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="4.191" x2="-27.559" y2="4.191" width="0.1524" layer="21"/>
<wire x1="-27.559" y1="3.429" x2="-28.448" y2="3.429" width="0.0508" layer="21"/>
<wire x1="-28.829" y1="4.191" x2="-32.512" y2="4.191" width="0.1524" layer="21"/>
<wire x1="-21.971" y1="-4.191" x2="-21.59" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="-21.971" y1="-4.191" x2="-23.495" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="-3.683" x2="-18.669" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-19.558" y1="-3.683" x2="-21.082" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="-21.082" y1="-3.683" x2="-21.59" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="-21.082" y1="-3.429" x2="-21.082" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="-21.082" y1="-3.429" x2="-26.162" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="-21.082" y1="-3.175" x2="-21.082" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="-21.082" y1="-3.175" x2="-28.194" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-19.558" y1="-3.175" x2="-19.558" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="-19.558" y1="-3.175" x2="-21.082" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-19.558" y1="-3.429" x2="-19.558" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="-3.683" x2="-19.558" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="-27.559" y1="-4.191" x2="-27.559" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="-27.559" y1="-4.191" x2="-32.512" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-27.559" y1="-3.429" x2="-28.448" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="-26.162" y1="-4.191" x2="-26.162" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="-26.162" y1="-4.191" x2="-27.559" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="-26.162" y1="-3.429" x2="-27.559" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="26.162" y1="-3.429" x2="26.162" y2="-4.191" width="0.0508" layer="21"/>
<wire x1="26.162" y1="-3.429" x2="27.559" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="26.162" y1="-4.191" x2="24.511" y2="-4.191" width="0.1524" layer="21"/>
<wire x1="27.559" y1="-3.429" x2="27.559" y2="-4.191" width="0.0508" layer="21"/>
<wire x1="27.559" y1="-3.429" x2="28.448" y2="-3.429" width="0.0508" layer="21"/>
<wire x1="27.559" y1="-4.191" x2="26.162" y2="-4.191" width="0.1524" layer="21"/>
<circle x="33.02" y="-0.254" radius="2.286" width="0" layer="42"/>
<circle x="33.02" y="-0.254" radius="2.286" width="0" layer="43"/>
<circle x="-33.02" y="-0.254" radius="2.286" width="0" layer="42"/>
<circle x="-33.02" y="-0.254" radius="2.286" width="0" layer="43"/>
<pad name="1" x="-24.13" y="-1.27" drill="0.9144"/>
<pad name="2" x="-24.13" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="3" x="-21.59" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="4" x="-21.59" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="5" x="-19.05" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="6" x="-19.05" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="7" x="-16.51" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="8" x="-16.51" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="9" x="-13.97" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="10" x="-13.97" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="11" x="-11.43" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="12" x="-11.43" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="13" x="-8.89" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="14" x="-8.89" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="15" x="-6.35" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="16" x="-6.35" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="17" x="-3.81" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="18" x="-3.81" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="19" x="-1.27" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="20" x="-1.27" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="21" x="1.27" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="22" x="1.27" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="23" x="3.81" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="24" x="3.81" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="25" x="6.35" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="26" x="6.35" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="28" x="8.89" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="27" x="8.89" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="30" x="11.43" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="29" x="11.43" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="32" x="13.97" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="31" x="13.97" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="33" x="16.51" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="34" x="16.51" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="35" x="19.05" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="36" x="19.05" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="38" x="21.59" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="37" x="21.59" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="39" x="24.13" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="40" x="24.13" y="1.27" drill="0.9144" shape="octagon"/>
<text x="-25.781" y="-2.921" size="1.27" layer="21" ratio="10">1</text>
<text x="-25.908" y="1.651" size="1.27" layer="21" ratio="10">2</text>
<text x="-34.925" y="5.08" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-24.13" y="5.08" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-1.143" y="-3.937" size="1.27" layer="51" ratio="10">40</text>
<rectangle x1="-21.844" y1="1.016" x2="-21.336" y2="1.524" layer="51"/>
<rectangle x1="-24.384" y1="1.016" x2="-23.876" y2="1.524" layer="51"/>
<rectangle x1="-19.304" y1="1.016" x2="-18.796" y2="1.524" layer="51"/>
<rectangle x1="-14.224" y1="1.016" x2="-13.716" y2="1.524" layer="51"/>
<rectangle x1="-16.764" y1="1.016" x2="-16.256" y2="1.524" layer="51"/>
<rectangle x1="-21.844" y1="-1.524" x2="-21.336" y2="-1.016" layer="51"/>
<rectangle x1="-24.384" y1="-1.524" x2="-23.876" y2="-1.016" layer="51"/>
<rectangle x1="-19.304" y1="-1.524" x2="-18.796" y2="-1.016" layer="51"/>
<rectangle x1="-14.224" y1="-1.524" x2="-13.716" y2="-1.016" layer="51"/>
<rectangle x1="-16.764" y1="-1.524" x2="-16.256" y2="-1.016" layer="51"/>
<rectangle x1="30.734" y1="-2.032" x2="31.496" y2="2.032" layer="21"/>
<rectangle x1="32.512" y1="-0.381" x2="34.29" y2="0.381" layer="51"/>
<rectangle x1="-31.496" y1="-2.032" x2="-30.734" y2="2.032" layer="21"/>
<rectangle x1="-34.29" y1="-0.381" x2="-32.512" y2="0.381" layer="51"/>
<rectangle x1="-11.684" y1="1.016" x2="-11.176" y2="1.524" layer="51"/>
<rectangle x1="-11.684" y1="-1.524" x2="-11.176" y2="-1.016" layer="51"/>
<rectangle x1="-9.144" y1="1.016" x2="-8.636" y2="1.524" layer="51"/>
<rectangle x1="-9.144" y1="-1.524" x2="-8.636" y2="-1.016" layer="51"/>
<rectangle x1="-6.604" y1="1.016" x2="-6.096" y2="1.524" layer="51"/>
<rectangle x1="-6.604" y1="-1.524" x2="-6.096" y2="-1.016" layer="51"/>
<rectangle x1="-4.064" y1="1.016" x2="-3.556" y2="1.524" layer="51"/>
<rectangle x1="-1.524" y1="1.016" x2="-1.016" y2="1.524" layer="51"/>
<rectangle x1="1.016" y1="1.016" x2="1.524" y2="1.524" layer="51"/>
<rectangle x1="3.556" y1="1.016" x2="4.064" y2="1.524" layer="51"/>
<rectangle x1="6.096" y1="1.016" x2="6.604" y2="1.524" layer="51"/>
<rectangle x1="8.636" y1="1.016" x2="9.144" y2="1.524" layer="51"/>
<rectangle x1="11.176" y1="1.016" x2="11.684" y2="1.524" layer="51"/>
<rectangle x1="13.716" y1="1.016" x2="14.224" y2="1.524" layer="51"/>
<rectangle x1="16.256" y1="1.016" x2="16.764" y2="1.524" layer="51"/>
<rectangle x1="18.796" y1="1.016" x2="19.304" y2="1.524" layer="51"/>
<rectangle x1="21.336" y1="1.016" x2="21.844" y2="1.524" layer="51"/>
<rectangle x1="23.876" y1="1.016" x2="24.384" y2="1.524" layer="51"/>
<rectangle x1="-4.064" y1="-1.524" x2="-3.556" y2="-1.016" layer="51"/>
<rectangle x1="-1.524" y1="-1.524" x2="-1.016" y2="-1.016" layer="51"/>
<rectangle x1="1.016" y1="-1.524" x2="1.524" y2="-1.016" layer="51"/>
<rectangle x1="3.556" y1="-1.524" x2="4.064" y2="-1.016" layer="51"/>
<rectangle x1="6.096" y1="-1.524" x2="6.604" y2="-1.016" layer="51"/>
<rectangle x1="8.636" y1="-1.524" x2="9.144" y2="-1.016" layer="51"/>
<rectangle x1="11.176" y1="-1.524" x2="11.684" y2="-1.016" layer="51"/>
<rectangle x1="13.716" y1="-1.524" x2="14.224" y2="-1.016" layer="51"/>
<rectangle x1="16.256" y1="-1.524" x2="16.764" y2="-1.016" layer="51"/>
<rectangle x1="18.796" y1="-1.524" x2="19.304" y2="-1.016" layer="51"/>
<rectangle x1="21.336" y1="-1.524" x2="21.844" y2="-1.016" layer="51"/>
<rectangle x1="23.876" y1="-1.524" x2="24.384" y2="-1.016" layer="51"/>
<hole x="33.02" y="-0.254" drill="3.302"/>
<hole x="-33.02" y="-0.254" drill="3.302"/>
</package>
</packages>
<symbols>
<symbol name="40P">
<wire x1="3.81" y1="-27.94" x2="-3.81" y2="-27.94" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-15.24" x2="2.54" y2="-15.24" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-17.78" x2="2.54" y2="-17.78" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-20.32" x2="2.54" y2="-20.32" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-22.86" x2="2.54" y2="-22.86" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-25.4" x2="2.54" y2="-25.4" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-15.24" x2="-1.27" y2="-15.24" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-17.78" x2="-1.27" y2="-17.78" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-20.32" x2="-1.27" y2="-20.32" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-22.86" x2="-1.27" y2="-22.86" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-25.4" x2="-1.27" y2="-25.4" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="2.54" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-10.16" x2="2.54" y2="-10.16" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-12.7" x2="2.54" y2="-12.7" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.27" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="-1.27" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-7.62" x2="-1.27" y2="-7.62" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-10.16" x2="-1.27" y2="-10.16" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-12.7" x2="-1.27" y2="-12.7" width="0.6096" layer="94"/>
<wire x1="1.27" y1="10.16" x2="2.54" y2="10.16" width="0.6096" layer="94"/>
<wire x1="1.27" y1="7.62" x2="2.54" y2="7.62" width="0.6096" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="10.16" x2="-1.27" y2="10.16" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="7.62" x2="-1.27" y2="7.62" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-1.27" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.27" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.6096" layer="94"/>
<wire x1="-3.81" y1="25.4" x2="-3.81" y2="-27.94" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-27.94" x2="3.81" y2="25.4" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="25.4" x2="3.81" y2="25.4" width="0.4064" layer="94"/>
<wire x1="1.27" y1="22.86" x2="2.54" y2="22.86" width="0.6096" layer="94"/>
<wire x1="1.27" y1="20.32" x2="2.54" y2="20.32" width="0.6096" layer="94"/>
<wire x1="1.27" y1="17.78" x2="2.54" y2="17.78" width="0.6096" layer="94"/>
<wire x1="1.27" y1="15.24" x2="2.54" y2="15.24" width="0.6096" layer="94"/>
<wire x1="1.27" y1="12.7" x2="2.54" y2="12.7" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="22.86" x2="-1.27" y2="22.86" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="20.32" x2="-1.27" y2="20.32" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="17.78" x2="-1.27" y2="17.78" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="15.24" x2="-1.27" y2="15.24" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="12.7" x2="-1.27" y2="12.7" width="0.6096" layer="94"/>
<text x="-3.81" y="-30.48" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="26.162" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-25.4" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-22.86" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="-20.32" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="7.62" y="-17.78" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="9" x="7.62" y="-15.24" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="-7.62" y="-25.4" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="4" x="-7.62" y="-22.86" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="6" x="-7.62" y="-20.32" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="8" x="-7.62" y="-17.78" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="10" x="-7.62" y="-15.24" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="11" x="7.62" y="-12.7" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="13" x="7.62" y="-10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="15" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="17" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="19" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="12" x="-7.62" y="-12.7" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="14" x="-7.62" y="-10.16" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="16" x="-7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="18" x="-7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="20" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="21" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="23" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="25" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="27" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="29" x="7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="22" x="-7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="24" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="26" x="-7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="28" x="-7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="30" x="-7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="31" x="7.62" y="12.7" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="33" x="7.62" y="15.24" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="35" x="7.62" y="17.78" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="37" x="7.62" y="20.32" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="39" x="7.62" y="22.86" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="32" x="-7.62" y="12.7" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="34" x="-7.62" y="15.24" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="36" x="-7.62" y="17.78" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="38" x="-7.62" y="20.32" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="40" x="-7.62" y="22.86" visible="pad" length="middle" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="40V" prefix="PL" uservalue="yes">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="40P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="40V">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="11" pad="11"/>
<connect gate="G$1" pin="12" pad="12"/>
<connect gate="G$1" pin="13" pad="13"/>
<connect gate="G$1" pin="14" pad="14"/>
<connect gate="G$1" pin="15" pad="15"/>
<connect gate="G$1" pin="16" pad="16"/>
<connect gate="G$1" pin="17" pad="17"/>
<connect gate="G$1" pin="18" pad="18"/>
<connect gate="G$1" pin="19" pad="19"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="20" pad="20"/>
<connect gate="G$1" pin="21" pad="21"/>
<connect gate="G$1" pin="22" pad="22"/>
<connect gate="G$1" pin="23" pad="23"/>
<connect gate="G$1" pin="24" pad="24"/>
<connect gate="G$1" pin="25" pad="25"/>
<connect gate="G$1" pin="26" pad="26"/>
<connect gate="G$1" pin="27" pad="27"/>
<connect gate="G$1" pin="28" pad="28"/>
<connect gate="G$1" pin="29" pad="29"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="30" pad="30"/>
<connect gate="G$1" pin="31" pad="31"/>
<connect gate="G$1" pin="32" pad="32"/>
<connect gate="G$1" pin="33" pad="33"/>
<connect gate="G$1" pin="34" pad="34"/>
<connect gate="G$1" pin="35" pad="35"/>
<connect gate="G$1" pin="36" pad="36"/>
<connect gate="G$1" pin="37" pad="37"/>
<connect gate="G$1" pin="38" pad="38"/>
<connect gate="G$1" pin="39" pad="39"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="40" pad="40"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="PL1" library="con-harting-v" deviceset="40V" device=""/>
<part name="PL2" library="con-harting-v" deviceset="40V" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="PL1" gate="G$1" x="40.64" y="43.18"/>
<instance part="PL2" gate="G$1" x="76.2" y="43.18" rot="MR0"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="1"/>
<pinref part="PL2" gate="G$1" pin="1"/>
<wire x1="68.58" y1="17.78" x2="48.26" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="3"/>
<pinref part="PL2" gate="G$1" pin="3"/>
<wire x1="68.58" y1="20.32" x2="48.26" y2="20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="5"/>
<pinref part="PL2" gate="G$1" pin="5"/>
<wire x1="68.58" y1="22.86" x2="48.26" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="7"/>
<pinref part="PL2" gate="G$1" pin="7"/>
<wire x1="68.58" y1="25.4" x2="48.26" y2="25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="9"/>
<pinref part="PL2" gate="G$1" pin="9"/>
<wire x1="68.58" y1="27.94" x2="48.26" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="11"/>
<pinref part="PL2" gate="G$1" pin="11"/>
<wire x1="68.58" y1="30.48" x2="48.26" y2="30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="13"/>
<pinref part="PL2" gate="G$1" pin="13"/>
<wire x1="68.58" y1="33.02" x2="48.26" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="15"/>
<pinref part="PL2" gate="G$1" pin="15"/>
<wire x1="68.58" y1="35.56" x2="48.26" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="17"/>
<pinref part="PL2" gate="G$1" pin="17"/>
<wire x1="68.58" y1="38.1" x2="48.26" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="19"/>
<pinref part="PL2" gate="G$1" pin="19"/>
<wire x1="68.58" y1="40.64" x2="48.26" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="21"/>
<pinref part="PL2" gate="G$1" pin="21"/>
<wire x1="68.58" y1="43.18" x2="48.26" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="23"/>
<pinref part="PL2" gate="G$1" pin="23"/>
<wire x1="68.58" y1="45.72" x2="48.26" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="25"/>
<pinref part="PL2" gate="G$1" pin="25"/>
<wire x1="68.58" y1="48.26" x2="48.26" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="27"/>
<pinref part="PL2" gate="G$1" pin="27"/>
<wire x1="68.58" y1="50.8" x2="48.26" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="29"/>
<pinref part="PL2" gate="G$1" pin="29"/>
<wire x1="68.58" y1="53.34" x2="48.26" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="31"/>
<pinref part="PL2" gate="G$1" pin="31"/>
<wire x1="68.58" y1="55.88" x2="48.26" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="33"/>
<pinref part="PL2" gate="G$1" pin="33"/>
<wire x1="68.58" y1="58.42" x2="48.26" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="35"/>
<pinref part="PL2" gate="G$1" pin="35"/>
<wire x1="68.58" y1="60.96" x2="48.26" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="37"/>
<pinref part="PL2" gate="G$1" pin="37"/>
<wire x1="68.58" y1="63.5" x2="48.26" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="39"/>
<pinref part="PL2" gate="G$1" pin="39"/>
<wire x1="68.58" y1="66.04" x2="48.26" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="2"/>
<wire x1="33.02" y1="17.78" x2="30.48" y2="17.78" width="0.1524" layer="91"/>
<wire x1="30.48" y1="17.78" x2="30.48" y2="10.16" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="2"/>
<wire x1="30.48" y1="10.16" x2="83.82" y2="10.16" width="0.1524" layer="91"/>
<wire x1="83.82" y1="10.16" x2="83.82" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="4"/>
<wire x1="33.02" y1="20.32" x2="27.94" y2="20.32" width="0.1524" layer="91"/>
<wire x1="27.94" y1="20.32" x2="27.94" y2="5.08" width="0.1524" layer="91"/>
<wire x1="27.94" y1="5.08" x2="88.9" y2="5.08" width="0.1524" layer="91"/>
<wire x1="88.9" y1="5.08" x2="88.9" y2="20.32" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="4"/>
<wire x1="88.9" y1="20.32" x2="83.82" y2="20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="6"/>
<wire x1="33.02" y1="22.86" x2="25.4" y2="22.86" width="0.1524" layer="91"/>
<wire x1="25.4" y1="22.86" x2="25.4" y2="2.54" width="0.1524" layer="91"/>
<wire x1="25.4" y1="2.54" x2="93.98" y2="2.54" width="0.1524" layer="91"/>
<wire x1="93.98" y1="2.54" x2="93.98" y2="22.86" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="6"/>
<wire x1="93.98" y1="22.86" x2="83.82" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="8"/>
<wire x1="33.02" y1="25.4" x2="22.86" y2="25.4" width="0.1524" layer="91"/>
<wire x1="22.86" y1="25.4" x2="22.86" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-2.54" x2="96.52" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="96.52" y1="-2.54" x2="96.52" y2="25.4" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="8"/>
<wire x1="96.52" y1="25.4" x2="83.82" y2="25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="10"/>
<wire x1="33.02" y1="27.94" x2="20.32" y2="27.94" width="0.1524" layer="91"/>
<wire x1="20.32" y1="27.94" x2="20.32" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-7.62" x2="99.06" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="99.06" y1="-7.62" x2="99.06" y2="27.94" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="10"/>
<wire x1="99.06" y1="27.94" x2="83.82" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="12"/>
<wire x1="33.02" y1="30.48" x2="17.78" y2="30.48" width="0.1524" layer="91"/>
<wire x1="17.78" y1="30.48" x2="17.78" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="17.78" y1="-10.16" x2="101.6" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="101.6" y1="-10.16" x2="101.6" y2="30.48" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="12"/>
<wire x1="101.6" y1="30.48" x2="83.82" y2="30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="14"/>
<wire x1="33.02" y1="33.02" x2="15.24" y2="33.02" width="0.1524" layer="91"/>
<wire x1="15.24" y1="33.02" x2="15.24" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="15.24" y1="-12.7" x2="104.14" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="104.14" y1="-12.7" x2="104.14" y2="33.02" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="14"/>
<wire x1="104.14" y1="33.02" x2="83.82" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="16"/>
<wire x1="33.02" y1="35.56" x2="12.7" y2="35.56" width="0.1524" layer="91"/>
<wire x1="12.7" y1="35.56" x2="12.7" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-15.24" x2="106.68" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="106.68" y1="-15.24" x2="106.68" y2="35.56" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="16"/>
<wire x1="106.68" y1="35.56" x2="83.82" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$29" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="18"/>
<wire x1="33.02" y1="38.1" x2="10.16" y2="38.1" width="0.1524" layer="91"/>
<wire x1="10.16" y1="38.1" x2="10.16" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-17.78" x2="109.22" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="109.22" y1="-17.78" x2="109.22" y2="38.1" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="18"/>
<wire x1="109.22" y1="38.1" x2="83.82" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="20"/>
<wire x1="33.02" y1="40.64" x2="7.62" y2="40.64" width="0.1524" layer="91"/>
<wire x1="7.62" y1="40.64" x2="7.62" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="7.62" y1="-22.86" x2="111.76" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="111.76" y1="-22.86" x2="111.76" y2="40.64" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="20"/>
<wire x1="111.76" y1="40.64" x2="83.82" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$31" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="40"/>
<wire x1="33.02" y1="66.04" x2="30.48" y2="66.04" width="0.1524" layer="91"/>
<wire x1="30.48" y1="66.04" x2="30.48" y2="71.12" width="0.1524" layer="91"/>
<wire x1="30.48" y1="71.12" x2="86.36" y2="71.12" width="0.1524" layer="91"/>
<wire x1="86.36" y1="71.12" x2="86.36" y2="66.04" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="40"/>
<wire x1="86.36" y1="66.04" x2="83.82" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$32" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="38"/>
<wire x1="33.02" y1="63.5" x2="27.94" y2="63.5" width="0.1524" layer="91"/>
<wire x1="27.94" y1="63.5" x2="27.94" y2="73.66" width="0.1524" layer="91"/>
<wire x1="27.94" y1="73.66" x2="88.9" y2="73.66" width="0.1524" layer="91"/>
<wire x1="88.9" y1="73.66" x2="88.9" y2="63.5" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="38"/>
<wire x1="88.9" y1="63.5" x2="83.82" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$33" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="36"/>
<wire x1="33.02" y1="60.96" x2="25.4" y2="60.96" width="0.1524" layer="91"/>
<wire x1="25.4" y1="60.96" x2="25.4" y2="76.2" width="0.1524" layer="91"/>
<wire x1="25.4" y1="76.2" x2="91.44" y2="76.2" width="0.1524" layer="91"/>
<wire x1="91.44" y1="76.2" x2="91.44" y2="60.96" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="36"/>
<wire x1="91.44" y1="60.96" x2="83.82" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$34" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="34"/>
<wire x1="33.02" y1="58.42" x2="22.86" y2="58.42" width="0.1524" layer="91"/>
<wire x1="22.86" y1="58.42" x2="22.86" y2="78.74" width="0.1524" layer="91"/>
<wire x1="22.86" y1="78.74" x2="93.98" y2="78.74" width="0.1524" layer="91"/>
<wire x1="93.98" y1="78.74" x2="93.98" y2="58.42" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="34"/>
<wire x1="93.98" y1="58.42" x2="83.82" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$35" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="32"/>
<wire x1="33.02" y1="55.88" x2="20.32" y2="55.88" width="0.1524" layer="91"/>
<wire x1="20.32" y1="55.88" x2="20.32" y2="81.28" width="0.1524" layer="91"/>
<wire x1="20.32" y1="81.28" x2="96.52" y2="81.28" width="0.1524" layer="91"/>
<wire x1="96.52" y1="81.28" x2="96.52" y2="55.88" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="32"/>
<wire x1="96.52" y1="55.88" x2="83.82" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$36" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="30"/>
<wire x1="33.02" y1="53.34" x2="17.78" y2="53.34" width="0.1524" layer="91"/>
<wire x1="17.78" y1="53.34" x2="17.78" y2="83.82" width="0.1524" layer="91"/>
<wire x1="17.78" y1="83.82" x2="99.06" y2="83.82" width="0.1524" layer="91"/>
<wire x1="99.06" y1="83.82" x2="99.06" y2="53.34" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="30"/>
<wire x1="99.06" y1="53.34" x2="83.82" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$37" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="28"/>
<wire x1="33.02" y1="50.8" x2="15.24" y2="50.8" width="0.1524" layer="91"/>
<wire x1="15.24" y1="50.8" x2="15.24" y2="86.36" width="0.1524" layer="91"/>
<wire x1="15.24" y1="86.36" x2="101.6" y2="86.36" width="0.1524" layer="91"/>
<wire x1="101.6" y1="86.36" x2="101.6" y2="50.8" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="28"/>
<wire x1="101.6" y1="50.8" x2="83.82" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$38" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="26"/>
<wire x1="33.02" y1="48.26" x2="12.7" y2="48.26" width="0.1524" layer="91"/>
<wire x1="12.7" y1="48.26" x2="12.7" y2="88.9" width="0.1524" layer="91"/>
<wire x1="12.7" y1="88.9" x2="104.14" y2="88.9" width="0.1524" layer="91"/>
<wire x1="104.14" y1="88.9" x2="104.14" y2="48.26" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="26"/>
<wire x1="104.14" y1="48.26" x2="83.82" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$39" class="0">
<segment>
<pinref part="PL1" gate="G$1" pin="24"/>
<wire x1="33.02" y1="45.72" x2="10.16" y2="45.72" width="0.1524" layer="91"/>
<wire x1="10.16" y1="45.72" x2="10.16" y2="91.44" width="0.1524" layer="91"/>
<wire x1="10.16" y1="91.44" x2="106.68" y2="91.44" width="0.1524" layer="91"/>
<wire x1="106.68" y1="91.44" x2="106.68" y2="45.72" width="0.1524" layer="91"/>
<pinref part="PL2" gate="G$1" pin="24"/>
<wire x1="106.68" y1="45.72" x2="83.82" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$40" class="0">
<segment>
<pinref part="PL2" gate="G$1" pin="22"/>
<wire x1="83.82" y1="43.18" x2="109.22" y2="43.18" width="0.1524" layer="91"/>
<wire x1="109.22" y1="43.18" x2="109.22" y2="93.98" width="0.1524" layer="91"/>
<wire x1="109.22" y1="93.98" x2="7.62" y2="93.98" width="0.1524" layer="91"/>
<wire x1="7.62" y1="93.98" x2="7.62" y2="43.18" width="0.1524" layer="91"/>
<pinref part="PL1" gate="G$1" pin="22"/>
<wire x1="7.62" y1="43.18" x2="33.02" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
