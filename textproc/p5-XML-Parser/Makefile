# $NetBSD: Makefile,v 1.17 2003/10/11 13:40:19 grant Exp $
#

DISTNAME=	XML-Parser-2.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5xpa
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bad@NetBSD.org
#HOMEPAGE=	http://wwwx.netheaven.com/~coopercc/xmlparser/intro.html
COMMENT=	Perl extension interface to James Clark's XML parser, expat

USE_BUILDLINK2=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
