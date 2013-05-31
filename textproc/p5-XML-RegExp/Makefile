# $NetBSD: Makefile,v 1.22 2013/05/31 12:42:21 wiz Exp $
#

DISTNAME=	XML-RegExp-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5xre
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide regular expressions for some XML tokens

CONFLICTS+=	p5-libxml-enno-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/RegExp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
