# $NetBSD: Makefile,v 1.13 2018/08/22 09:47:09 wiz Exp $

DISTNAME=	XML-SAX-Base-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX-Base/
COMMENT=	Perl base class SAX Drivers and Filters
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/XML/SAX/Base/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
