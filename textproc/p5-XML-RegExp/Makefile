# $NetBSD: Makefile,v 1.24 2014/05/29 23:37:47 wiz Exp $
#

DISTNAME=	XML-RegExp-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5xre
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide regular expressions for some XML tokens
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libxml-enno-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/RegExp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
