# $NetBSD: Makefile,v 1.5 2010/08/21 16:36:59 seb Exp $

DISTNAME=	Kwiki-Wikiwyg-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wikiwyg.net/
COMMENT=	Kwiki plugin for WYSIWYG editing

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.38:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/Wikiwyg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
