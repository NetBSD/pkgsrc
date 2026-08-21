package sqlite

import (
	"database/sql/driver"
	"errors"
)

type Driver struct {
}
type Error struct {
	msg  string
	code int
}

func (d *Driver) Open(name string) (conn driver.Conn, err error) {
	return nil, errors.New("not implemented")
}

func (e *Error) Error() string {
	return e.msg
}

func (e *Error) Code() int {
	return e.code
}
