# $NetBSD: Makefile,v 1.1.1.1 2003/10/05 11:51:47 wiz Exp $
#

DISTNAME=	XML-LibXML-Common-0.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xlc
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML-Common/
COMMENT=	Routines and constants common for XML::LibXML and XML::GDOME

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/LibXML/Common/.packlist

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
