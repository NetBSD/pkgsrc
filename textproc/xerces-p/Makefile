# $NetBSD: Makefile,v 1.7 2001/11/01 18:24:44 tron Exp $
#

DISTNAME=	XML-Xerces-1.3.5
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-p/

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://xml.apache.org/xerces-p/
COMMENT=	Validating XML parser API for Perl

DEPENDS+=	swig-1.1p5:../../devel/swig
DEPENDS+=	xerces-c-1.3.*:../../textproc/xerces-c
DEPENDS+=	icu>=1.7:../../textproc/icu

USE_PERL5=	# defined
PERL5_REQD=	5.6.0
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Xerces/.packlist

MAKE_ENV+=	XERCES_LIB=${PREFIX}/lib
MAKE_ENV+=	XERCES_INCLUDE=${PREFIX}/include

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL && make

.include "../../mk/bsd.pkg.mk"
