# $NetBSD: Makefile,v 1.13 2011/08/14 16:06:02 obache Exp $

DISTNAME=	Kwiki-UserName-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki user name plugin

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki
DEPENDS+=	p5-Kwiki-UserPreferences>=0.13:../../www/p5-Kwiki-UserPreferences

PERL5_PACKLIST=		auto/Kwiki/UserName/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
