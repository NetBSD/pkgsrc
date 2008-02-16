# $NetBSD: Makefile,v 1.1.1.1 2008/02/16 05:02:36 obache Exp $

DISTNAME=	I18N-AcceptLanguage-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ial
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=I18N/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/I18N-AcceptLanguage/
COMMENT=	Matches language preference to available languages

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/I18N/AcceptLanguage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
