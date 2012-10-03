# $NetBSD: Makefile,v 1.25 2012/10/03 21:58:46 wiz Exp $

DISTNAME=		HTML-Template-2.91
PKGNAME=		p5-${DISTNAME:S/91/9.1/}
PKGREVISION=		1
SVR4_PKGNAME=		p5htm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/} \
			${MASTER_SITE_SOURCEFORGE:=html-template/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://html-template.sourceforge.net/
COMMENT=		Perl5 module to create HTML templates with simple tags
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/HTML/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
