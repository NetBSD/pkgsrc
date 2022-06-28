# $NetBSD: Makefile,v 1.34 2022/06/28 11:36:43 wiz Exp $
#

DISTNAME=	XML-RegExp-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide regular expressions for some XML tokens
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libxml-enno-[0-9]*

PERL5_PACKLIST=		auto/XML/RegExp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
