# $NetBSD: Makefile,v 1.1.1.1 2001/04/12 19:23:24 manu Exp $
#

DISTNAME=	XML-Xerces-1.3.3
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-p/

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	
COMMENT=		Validating XML parser API for Perl

DEPENDS+=   perl>={5.00560,5.6.0}:../../lang/perl5
DEPENDS+=   perl-base>=5.6.0nb1:../../lang/perl5-base
DEPENDS+=   swig>=1.1p5:../../devel/swig
DEPENDS+=   xerces-c>=1.3.0:../../textproc/xerces-c
DEPENDS+=   icu>=1.7:../../textproc/icu

MAKE_ENV+=	XERCES_LIB=/usr/pkg/lib
MAKE_ENV+=	XERCES_INCLUDE=/usr/pkg/include

do-build:
	cd ${WRKSRC} && perl Makefile.PL && make 

.include "../../mk/bsd.pkg.mk"
