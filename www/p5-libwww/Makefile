# $NetBSD: Makefile,v 1.57 2008/04/22 21:48:58 wiz Exp $

DISTNAME=	libwww-perl-5.812
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
SVR4_PKGNAME=	p5lww
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libwww-perl/
COMMENT=	Perl5 library for WWW access

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net>=1.09:../../net/p5-Net		# for Net::FTP>=2.58
DEPENDS+=	p5-URI>=1.10:../../www/p5-URI
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/LWP/.packlist
MAKE_ENV+=		INSTALL_ALIASES=${ALIASES} PERL_MM_USE_DEFAULT=1

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${ALIASES} == "no"
post-install:
	${RM} -f ${PREFIX}/bin/HEAD
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
