geosdb
======

Wrapper of Boost' geometry for SciDB.


<h3>Files:</h3>
<ul>
	<li><code>LICENSE</code> - License file.</li>
	<li><code>README.md</code> - This file.</li>
	<li><code>CMakeLists.txt</code> - Cmake script for building the plug-in.</li>
	<li><code>geosdb.cpp</code> - Implementation code.</li>
</ul>

<h3>Prerequisites:</h3>
<ul>
	<li><a href="http://www.scidb.org/">SciDB</a>'s source code. A Docker image for that can be found <a href="http://github.com/albhasan/docker_scidb">here</a>.</li>
	<li><a href="http://www.boost.org/">Boost</a> libraries. An installation script is available <a href="http://github.com/albhasan/amazonGreenUp2005/blob/master/installBoost_1570.sh">here</a></li>
</ul>



<h3>Instructions:</h3>
<ol>
	<li>Get SciDB's source code. Then decompress SciDB's files to <code>/home/scidb/dev_dir/scidbtrunk</code></li>
	<li>Go to <code>cd /home/scidb/dev_dir/scidbtrunk/examples</code> and clone this project: <code>git clone http://github.com/albhasan/geosdb.git</code></li>
	<li>Modify the file <code>nano /home/scidb/dev_dir/scidbtrunk/examples/CMakeLists.txt</code> and add this line at the end of the file <code>add_subdirectory("geosdb")</code></li>
	<li>Build SciDB from source code as usual. If SciDB was already build, you must:
		<ol>
			<li>Go to <code>cd /home/scidb/dev_dir/scidbtrunk/examples</code></li>
			<li>Run <code>cmake ..</code></li>
			<li>Run <code>make</code></li>
			<li>Run <code>sudo make install</code></li>
			<li>Copy the file <code>cp /home/scidb/dev_dir/scidbtrunk/examples/bin/plugins/libgeosdb.so /home/scidb/dev_dir/scidbtrunk/stage/install/lib/scidb/plugins/libgeosdb.so</code></li>
		</ol>
	</li>
	<li>Test the installation:
		<ol>
			<li>Start the database <code>/home/scidb/dev_dir/scidbtrunk/./run.py stop</code></li>
			<li>Switch to AFL <code>set lang afl;</code></li>
			<li>Load the plug-in <code>load_library('geosdb');</code></li>
			<li>Run a test <code>build(<val:bool>[i=0:3,4,0,j=0:3,4,0], ispointinpolygon(double(i), double(j), 'POLYGON ((1.0 1.0, 4.0 1.0, 4.0 4.0, 1.0 4.0, 1.0 1.0))'));</code></li>
		</ol>	
	</li>

</ol>



