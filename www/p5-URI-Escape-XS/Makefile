# $NetBSD: Makefile,v 1.10 2011/08/14 16:06:11 obache Exp $

DISTNAME=	URI-Escape-XS-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/URI-Escape-XS/
COMMENT=	Escape and unescape unsafe characters in URIs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI>=1.35:../../www/p5-URI

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/URI/Escape/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
