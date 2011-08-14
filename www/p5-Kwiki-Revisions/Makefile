# $NetBSD: Makefile,v 1.14 2011/08/14 16:06:01 obache Exp $

DISTNAME=	Kwiki-Revisions-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki revisions plugin

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.38:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Revisions/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
