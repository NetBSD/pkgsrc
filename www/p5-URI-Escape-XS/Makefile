# $NetBSD: Makefile,v 1.4 2009/05/12 11:09:26 martti Exp $

DISTNAME=	URI-Escape-XS-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/URI-Escape-XS/
COMMENT=	Escape and unescape unsafe characters in URIs
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-URI>=1.35:../../www/p5-URI

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/URI/Escape/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
