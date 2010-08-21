# $NetBSD: Makefile,v 1.4 2010/08/21 16:36:12 seb Exp $

DISTNAME=	XML-Handler-Trees-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5xht
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Handler-Trees/
COMMENT=	PerlSAX handlers for building tree structures

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/Handler/Trees/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
