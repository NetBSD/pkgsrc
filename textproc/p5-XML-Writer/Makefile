# $NetBSD: Makefile,v 1.26 2013/05/31 12:42:22 wiz Exp $
#

DISTNAME=	XML-Writer-0.615
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5xwr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://xml-writer-perl.berlios.de/
COMMENT=	Perl module for writing XML documents
#LICENSE=	?
# Redistribution and use in source and compiled forms, with or without
# modification, are permitted under any circumstances.  No warranty.

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Writer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
