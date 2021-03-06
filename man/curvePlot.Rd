% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/wrappers.R
\name{curvePlot}
\alias{curvePlot}
\title{Plot of Base Quality and GC Content.}
\usage{
curvePlot(json, curves = "quality_curves")
}
\arguments{
\item{json}{the output json of function rfastq. [json]}

\item{curves}{plots for Base Quality("quality_curves")
or GC content("content_curves"). default is "quality_curves"}
}
\value{
a ggplot2 object.
}
\description{
generate a ggplot2 object of Base Quality/GC content before and after QC.
}
\examples{
outputPrefix <- tempfile(tmpdir = tempdir())
se_read1 <- system.file("extdata","Fox3_Std_small.fq.gz",package="Rfastp")
se_json_report <- rfastp(read1 = se_read1, outputFastq = outputPrefix,
   thread = 4)
# Base Quality plot is the default output:
p1 <- curvePlot(se_json_report)
p1

p2 <- curvePlot(se_json_report, curves = "content_curves")
}
\author{
Wei Wang
}
