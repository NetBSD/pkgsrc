# $NetBSD: Makefile,v 1.8 2002/10/30 09:43:35 seb Exp $
#

DISTNAME=	XML-Xerces-1.3.5
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-p/

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://xml.apache.org/xerces-p/
COMMENT=	Validating XML parser API for Perl

DEPENDS+=	swig-1.1p5:../../devel/swig

USE_BUILDLINK2=	YES
PERL5_REQD=	5.6.0
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Xerces/.packlist

MAKE_ENV+=	XERCES_LIB=${BUILDLINK_PREFIX.xerces-c}/lib
MAKE_ENV+=	XERCES_INCLUDE=${BUILDLINK_PREFIX.xerces-c}/include

BUILDLINK_TRANSFORM+=	s:-lpthread:

.include "../../lang/perl5/module.mk"
.include "../../textproc/xerces-c/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
