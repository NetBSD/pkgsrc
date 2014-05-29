# $NetBSD: Makefile,v 1.10 2014/05/29 23:38:11 wiz Exp $

DISTNAME=	Kwiki-Wikiwyg-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wikiwyg.net/
COMMENT=	Kwiki plugin for WYSIWYG editing

DEPENDS+=	p5-Kwiki>=0.38:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/Wikiwyg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
