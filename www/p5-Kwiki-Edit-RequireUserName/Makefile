# $NetBSD: Makefile,v 1.7 2011/08/14 16:06:00 obache Exp $

DISTNAME=	Kwiki-Edit-RequireUserName-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/JPEREGR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to require a user name to edit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Edit/RequireUserName/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
