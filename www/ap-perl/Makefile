# $NetBSD: Makefile,v 1.5 1999/05/01 00:42:29 tv Exp $
#

DISTNAME=       	mod_perl-1.19
PKGNAME=        	ap-perl-1.19
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://perl.apache.org/

DEPENDS=		libperl-5.00404:../../lang/libperl \
			apache-1.3.6p0:../../www/apache
USE_PERL5=		yes

MAKE_ENV=		DYNALOADER_OBJ_PIC="${PREFIX}/lib/perl5/${MACHINE_ARCH}-${LOWER_OPSYS}/5.00404/DynaLoader_pic.o"

do-configure:
	@cd ${WRKSRC} && ${PREFIX}/bin/perl Makefile.PL USE_APXS=1 \
		WITH_APXS=${PREFIX}/sbin/apxs EVERYTHING=1

post-install:
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/
.if exists(/usr/libexec/ld.elf_so)
	${SED}	-e 's,@@MACHINE_ARCH@@,${MACHINE_ARCH},' \
		-e 's,@@PERL_EXT@@,,' ${FILESDIR}/httpd.conf.add >${WRKSRC}/httpd.conf.add
.else
	${SED}	-e 's,@@MACHINE_ARCH@@,${MACHINE_ARCH},' \
		-e 's,@@PERL_EXT@@,.4.4,' ${FILESDIR}/httpd.conf.add >${WRKSRC}/httpd.conf.add
.endif
	${INSTALL_DATA} ${WRKSRC}/httpd.conf.add ${PREFIX}/etc/httpd/httpd.conf.modperl

.include "../../mk/bsd.pkg.mk"
